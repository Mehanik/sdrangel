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

#ifndef SDRBASE_PIPES_MESSAGEPIPES_H_
#define SDRBASE_PIPES_MESSAGEPIPES_H_

#include <QObject>
#include <QHash>
#include <QMap>
#include <QMutex>
#include <QThread>

#include "export.h"
#include "util/messagequeue.h"

#include "messagepipescommon.h"

class ChannelAPI;
class Feature;
class MessagePipesGCWorker;

class SDRBASE_API MessagePipes : public QObject
{
    Q_OBJECT
public:
    MessagePipes();
    MessagePipes(const MessagePipes&) = delete;
    MessagePipes& operator=(const MessagePipes&) = delete;
    ~MessagePipes();

    MessageQueue *registerChannelToFeature(const ChannelAPI *source, Feature *feature, const QString& type);
    void unregisterChannelToFeature(const ChannelAPI *source, Feature *feature, const QString& type);
    QList<MessageQueue*>* getMessageQueues(const ChannelAPI *source, const QString& type);

private:
    QHash<QString, int> m_typeIds;
    int m_typeCount;
    QMap<MessagePipesCommon::ChannelRegistrationKey, QList<MessageQueue*>> m_c2fQueues;
    QMap<MessagePipesCommon::ChannelRegistrationKey, QList<Feature*>> m_c2fFEatures;
    QMutex m_c2fMutex;
    QThread m_gcThread; //!< Garbage collector thread
    MessagePipesGCWorker *m_gcWorker; //!< Garbage collector

	void startGC(); //!< Start garbage collector
	void stopGC();  //!< Stop garbage collector
};

#endif // SDRBASE_PIPES_MESSAGEPIPES_H_