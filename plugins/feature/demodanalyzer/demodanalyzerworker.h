///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef INCLUDE_DEMODALYZERWORKER_H
#define INCLUDE_DEMODALYZERWORKER_H

#include <vector>

#include <QObject>
#include <QMutex>
#include <QByteArray>

#include "dsp/dsptypes.h"
#include "dsp/decimators.h"
#include "util/movingaverage.h"
#include "util/message.h"
#include "util/messagequeue.h"

#include "demodanalyzersettings.h"

class BasebandSampleSink;
class ChannelAPI;
class Feature;
class DataFifo;

class DemodAnalyzerWorker : public QObject {
    Q_OBJECT
public:
    class MsgConfigureDemodAnalyzerWorker : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const DemodAnalyzerSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureDemodAnalyzerWorker* create(const DemodAnalyzerSettings& settings, bool force)
        {
            return new MsgConfigureDemodAnalyzerWorker(settings, force);
        }

    private:
        DemodAnalyzerSettings m_settings;
        bool m_force;

        MsgConfigureDemodAnalyzerWorker(const DemodAnalyzerSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    class MsgConnectFifo : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        DataFifo *getFifo() { return m_fifo; }
        bool getConnect() const { return m_connect; }

        static MsgConnectFifo* create(DataFifo *fifo, bool connect) {
            return new MsgConnectFifo(fifo, connect);
        }
    private:
        DataFifo *m_fifo;
        bool m_connect;
        MsgConnectFifo(DataFifo *fifo, bool connect) :
            Message(),
            m_fifo(fifo),
            m_connect(connect)
        { }
    };

    DemodAnalyzerWorker();
	~DemodAnalyzerWorker();
    void reset();
    bool startWork();
    void stopWork();
    bool isRunning() const { return m_running; }
    MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }
    void setMessageQueueToFeature(MessageQueue *messageQueue) { m_msgQueueToFeature = messageQueue; }

    void feedPart(const QByteArray::const_iterator& begin, const QByteArray::const_iterator& end);

    void applySampleRate(int sampleRate);
	void applySettings(const DemodAnalyzerSettings& settings, bool force = false);

	double getMagSq() const { return m_magsq; }
	double getMagSqAvg() const { return (double) m_channelPowerAvg; }
    void setSampleSink(BasebandSampleSink* sampleSink) { m_sampleSink = sampleSink; }

    static const unsigned int m_corrFFTLen;
    static const unsigned int m_ssbFftLen;

private:
    DataFifo *m_dataFifo;
    int m_channelSampleRate;
    int m_sinkSampleRate;
	MessageQueue m_inputMessageQueue;  //!< Queue for asynchronous inbound communication
    MessageQueue *m_msgQueueToFeature; //!< Queue to report channel change to main feature object
    DemodAnalyzerSettings m_settings;
	double m_magsq;
	SampleVector m_sampleBuffer;
    std::vector<qint16> m_convBuffer;
    Decimators<qint32, qint16, SDR_RX_SAMP_SZ, 16, true> m_decimators;
    int m_sampleBufferSize;
	MovingAverageUtil<double, double, 480> m_channelPowerAvg;
    BasebandSampleSink* m_sampleSink;
    bool m_running;
    QMutex m_mutex;

    bool handleMessage(const Message& cmd);
    void decimate(int countSamples);

private slots:
    void handleInputMessages();
    void handleData(); //!< Handle data when samples have to be processed
};

#endif // INCLUDE_DEMODALYZERWORKER_H
