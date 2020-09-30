///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB                                   //
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

#ifndef SDRSRV_DEVICE_DEVICESET_H_
#define SDRSRV_DEVICE_DEVICESET_H_

#include <QTimer>

class DeviceAPI;
class DSPDeviceSourceEngine;
class DSPDeviceSinkEngine;
class DSPDeviceMIMOEngine;
class PluginAPI;
class ChannelAPI;
class Preset;
class SpectrumVis;

namespace SWGSDRangel {
    class SWGGLSpectrum;
    class SWGSpectrumServer;
    class SWGSuccessResponse;
};

class DeviceSet
{
public:
    DeviceAPI *m_deviceAPI;
    DSPDeviceSourceEngine *m_deviceSourceEngine;
    DSPDeviceSinkEngine *m_deviceSinkEngine;
    DSPDeviceMIMOEngine *m_deviceMIMOEngine;
    SpectrumVis *m_spectrumVis;

    DeviceSet(int tabIndex, int deviceType);
    ~DeviceSet();

    int getNumberOfChannels() const { return m_channelInstanceRegistrations.size(); }
    void freeChannels();
    void deleteChannel(int channelIndex);
    void loadRxChannelSettings(const Preset* preset, PluginAPI *pluginAPI);
    void saveRxChannelSettings(Preset* preset);
    void loadTxChannelSettings(const Preset* preset, PluginAPI *pluginAPI);
    void saveTxChannelSettings(Preset* preset);
    void loadMIMOChannelSettings(const Preset* preset, PluginAPI *pluginAPI);
    void saveMIMOChannelSettings(Preset* preset);
    void addRxChannel(int selectedChannelIndex, PluginAPI *pluginAPI);
    void addTxChannel(int selectedChannelIndex, PluginAPI *pluginAPI);
    void addMIMOChannel(int selectedChannelIndex, PluginAPI *pluginAPI);

    // REST API
    int webapiSpectrumSettingsGet(SWGSDRangel::SWGGLSpectrum& response, QString& errorMessage) const;
    int webapiSpectrumSettingsPutPatch(
            bool force,
            const QStringList& spectrumSettingsKeys,
            SWGSDRangel::SWGGLSpectrum& response, // query + response
            QString& errorMessage);
    int webapiSpectrumServerGet(SWGSDRangel::SWGSpectrumServer& response, QString& errorMessage) const;
    int webapiSpectrumServerPost(SWGSDRangel::SWGSuccessResponse& response, QString& errorMessage);
    int webapiSpectrumServerDelete(SWGSDRangel::SWGSuccessResponse& response, QString& errorMessage);

private:
    struct ChannelInstanceRegistration
    {
        QString m_channelName;
        ChannelAPI *m_channelAPI;

        ChannelInstanceRegistration() :
            m_channelName(),
            m_channelAPI(nullptr)
        { }

        ChannelInstanceRegistration(const QString& channelName, ChannelAPI* channelAPI);

        bool operator<(const ChannelInstanceRegistration& other) const;
    };

    typedef QList<ChannelInstanceRegistration> ChannelInstanceRegistrations;

    ChannelInstanceRegistrations m_channelInstanceRegistrations;
    int m_deviceTabIndex;

    void renameChannelInstances();
};

#endif /* SDRSRV_DEVICE_DEVICESET_H_ */
