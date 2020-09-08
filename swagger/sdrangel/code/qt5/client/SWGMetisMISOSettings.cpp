/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 5.9.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGMetisMISOSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGMetisMISOSettings::SWGMetisMISOSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGMetisMISOSettings::SWGMetisMISOSettings() {
    nb_receivers = 0;
    m_nb_receivers_isSet = false;
    tx_enable = 0;
    m_tx_enable_isSet = false;
    rx_center_frequencies = new QList<qint64>();
    m_rx_center_frequencies_isSet = false;
    tx_center_frequency = 0L;
    m_tx_center_frequency_isSet = false;
    rx_subsampling_indexes = new QList<qint32>();
    m_rx_subsampling_indexes_isSet = false;
    sample_rate_index = 0;
    m_sample_rate_index_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    preamp = 0;
    m_preamp_isSet = false;
    random = 0;
    m_random_isSet = false;
    dither = 0;
    m_dither_isSet = false;
    duplex = 0;
    m_duplex_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    tx_drive = 0;
    m_tx_drive_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGMetisMISOSettings::~SWGMetisMISOSettings() {
    this->cleanup();
}

void
SWGMetisMISOSettings::init() {
    nb_receivers = 0;
    m_nb_receivers_isSet = false;
    tx_enable = 0;
    m_tx_enable_isSet = false;
    rx_center_frequencies = new QList<qint64>();
    m_rx_center_frequencies_isSet = false;
    tx_center_frequency = 0L;
    m_tx_center_frequency_isSet = false;
    rx_subsampling_indexes = new QList<qint32>();
    m_rx_subsampling_indexes_isSet = false;
    sample_rate_index = 0;
    m_sample_rate_index_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    preamp = 0;
    m_preamp_isSet = false;
    random = 0;
    m_random_isSet = false;
    dither = 0;
    m_dither_isSet = false;
    duplex = 0;
    m_duplex_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    tx_drive = 0;
    m_tx_drive_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

void
SWGMetisMISOSettings::cleanup() {
















    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGMetisMISOSettings*
SWGMetisMISOSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGMetisMISOSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&nb_receivers, pJson["nbReceivers"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx_enable, pJson["txEnable"], "qint32", "");
    
    
    ::SWGSDRangel::setValue(&rx_center_frequencies, pJson["rxCenterFrequencies"], "QList", "qint64");
    ::SWGSDRangel::setValue(&tx_center_frequency, pJson["txCenterFrequency"], "qint64", "");
    
    
    ::SWGSDRangel::setValue(&rx_subsampling_indexes, pJson["rxSubsamplingIndexes"], "QList", "qint32");
    ::SWGSDRangel::setValue(&sample_rate_index, pJson["sampleRateIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&log2_decim, pJson["log2Decim"], "qint32", "");
    
    ::SWGSDRangel::setValue(&l_oppm_tenths, pJson["LOppmTenths"], "qint32", "");
    
    ::SWGSDRangel::setValue(&preamp, pJson["preamp"], "qint32", "");
    
    ::SWGSDRangel::setValue(&random, pJson["random"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dither, pJson["dither"], "qint32", "");
    
    ::SWGSDRangel::setValue(&duplex, pJson["duplex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGSDRangel::setValue(&iq_correction, pJson["iqCorrection"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx_drive, pJson["txDrive"], "qint32", "");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGMetisMISOSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGMetisMISOSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_nb_receivers_isSet){
        obj->insert("nbReceivers", QJsonValue(nb_receivers));
    }
    if(m_tx_enable_isSet){
        obj->insert("txEnable", QJsonValue(tx_enable));
    }
    if(rx_center_frequencies && rx_center_frequencies->size() > 0){
        toJsonArray((QList<void*>*)rx_center_frequencies, obj, "rxCenterFrequencies", "");
    }
    if(m_tx_center_frequency_isSet){
        obj->insert("txCenterFrequency", QJsonValue(tx_center_frequency));
    }
    if(rx_subsampling_indexes && rx_subsampling_indexes->size() > 0){
        toJsonArray((QList<void*>*)rx_subsampling_indexes, obj, "rxSubsamplingIndexes", "");
    }
    if(m_sample_rate_index_isSet){
        obj->insert("sampleRateIndex", QJsonValue(sample_rate_index));
    }
    if(m_log2_decim_isSet){
        obj->insert("log2Decim", QJsonValue(log2_decim));
    }
    if(m_l_oppm_tenths_isSet){
        obj->insert("LOppmTenths", QJsonValue(l_oppm_tenths));
    }
    if(m_preamp_isSet){
        obj->insert("preamp", QJsonValue(preamp));
    }
    if(m_random_isSet){
        obj->insert("random", QJsonValue(random));
    }
    if(m_dither_isSet){
        obj->insert("dither", QJsonValue(dither));
    }
    if(m_duplex_isSet){
        obj->insert("duplex", QJsonValue(duplex));
    }
    if(m_dc_block_isSet){
        obj->insert("dcBlock", QJsonValue(dc_block));
    }
    if(m_iq_correction_isSet){
        obj->insert("iqCorrection", QJsonValue(iq_correction));
    }
    if(m_tx_drive_isSet){
        obj->insert("txDrive", QJsonValue(tx_drive));
    }
    if(m_use_reverse_api_isSet){
        obj->insert("useReverseAPI", QJsonValue(use_reverse_api));
    }
    if(reverse_api_address != nullptr && *reverse_api_address != QString("")){
        toJsonValue(QString("reverseAPIAddress"), reverse_api_address, obj, QString("QString"));
    }
    if(m_reverse_api_port_isSet){
        obj->insert("reverseAPIPort", QJsonValue(reverse_api_port));
    }
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }

    return obj;
}

qint32
SWGMetisMISOSettings::getNbReceivers() {
    return nb_receivers;
}
void
SWGMetisMISOSettings::setNbReceivers(qint32 nb_receivers) {
    this->nb_receivers = nb_receivers;
    this->m_nb_receivers_isSet = true;
}

qint32
SWGMetisMISOSettings::getTxEnable() {
    return tx_enable;
}
void
SWGMetisMISOSettings::setTxEnable(qint32 tx_enable) {
    this->tx_enable = tx_enable;
    this->m_tx_enable_isSet = true;
}

QList<qint64>*
SWGMetisMISOSettings::getRxCenterFrequencies() {
    return rx_center_frequencies;
}
void
SWGMetisMISOSettings::setRxCenterFrequencies(QList<qint64>* rx_center_frequencies) {
    this->rx_center_frequencies = rx_center_frequencies;
    this->m_rx_center_frequencies_isSet = true;
}

qint64
SWGMetisMISOSettings::getTxCenterFrequency() {
    return tx_center_frequency;
}
void
SWGMetisMISOSettings::setTxCenterFrequency(qint64 tx_center_frequency) {
    this->tx_center_frequency = tx_center_frequency;
    this->m_tx_center_frequency_isSet = true;
}

QList<qint32>*
SWGMetisMISOSettings::getRxSubsamplingIndexes() {
    return rx_subsampling_indexes;
}
void
SWGMetisMISOSettings::setRxSubsamplingIndexes(QList<qint32>* rx_subsampling_indexes) {
    this->rx_subsampling_indexes = rx_subsampling_indexes;
    this->m_rx_subsampling_indexes_isSet = true;
}

qint32
SWGMetisMISOSettings::getSampleRateIndex() {
    return sample_rate_index;
}
void
SWGMetisMISOSettings::setSampleRateIndex(qint32 sample_rate_index) {
    this->sample_rate_index = sample_rate_index;
    this->m_sample_rate_index_isSet = true;
}

qint32
SWGMetisMISOSettings::getLog2Decim() {
    return log2_decim;
}
void
SWGMetisMISOSettings::setLog2Decim(qint32 log2_decim) {
    this->log2_decim = log2_decim;
    this->m_log2_decim_isSet = true;
}

qint32
SWGMetisMISOSettings::getLOppmTenths() {
    return l_oppm_tenths;
}
void
SWGMetisMISOSettings::setLOppmTenths(qint32 l_oppm_tenths) {
    this->l_oppm_tenths = l_oppm_tenths;
    this->m_l_oppm_tenths_isSet = true;
}

qint32
SWGMetisMISOSettings::getPreamp() {
    return preamp;
}
void
SWGMetisMISOSettings::setPreamp(qint32 preamp) {
    this->preamp = preamp;
    this->m_preamp_isSet = true;
}

qint32
SWGMetisMISOSettings::getRandom() {
    return random;
}
void
SWGMetisMISOSettings::setRandom(qint32 random) {
    this->random = random;
    this->m_random_isSet = true;
}

qint32
SWGMetisMISOSettings::getDither() {
    return dither;
}
void
SWGMetisMISOSettings::setDither(qint32 dither) {
    this->dither = dither;
    this->m_dither_isSet = true;
}

qint32
SWGMetisMISOSettings::getDuplex() {
    return duplex;
}
void
SWGMetisMISOSettings::setDuplex(qint32 duplex) {
    this->duplex = duplex;
    this->m_duplex_isSet = true;
}

qint32
SWGMetisMISOSettings::getDcBlock() {
    return dc_block;
}
void
SWGMetisMISOSettings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint32
SWGMetisMISOSettings::getIqCorrection() {
    return iq_correction;
}
void
SWGMetisMISOSettings::setIqCorrection(qint32 iq_correction) {
    this->iq_correction = iq_correction;
    this->m_iq_correction_isSet = true;
}

qint32
SWGMetisMISOSettings::getTxDrive() {
    return tx_drive;
}
void
SWGMetisMISOSettings::setTxDrive(qint32 tx_drive) {
    this->tx_drive = tx_drive;
    this->m_tx_drive_isSet = true;
}

qint32
SWGMetisMISOSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGMetisMISOSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGMetisMISOSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGMetisMISOSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGMetisMISOSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGMetisMISOSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGMetisMISOSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGMetisMISOSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGMetisMISOSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_nb_receivers_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_enable_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_center_frequencies_isSet){
            isObjectUpdated = true; break;
        }
        if(rx_center_frequencies && (rx_center_frequencies->size() > 0)){
            isObjectUpdated = true; break;
        }
        if(m_tx_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_subsampling_indexes_isSet){
            isObjectUpdated = true; break;
        }
        if(rx_subsampling_indexes && (rx_subsampling_indexes->size() > 0)){
            isObjectUpdated = true; break;
        }
        if(m_sample_rate_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_log2_decim_isSet){
            isObjectUpdated = true; break;
        }
        if(m_l_oppm_tenths_isSet){
            isObjectUpdated = true; break;
        }
        if(m_preamp_isSet){
            isObjectUpdated = true; break;
        }
        if(m_random_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dither_isSet){
            isObjectUpdated = true; break;
        }
        if(m_duplex_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dc_block_isSet){
            isObjectUpdated = true; break;
        }
        if(m_iq_correction_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_drive_isSet){
            isObjectUpdated = true; break;
        }
        if(m_use_reverse_api_isSet){
            isObjectUpdated = true; break;
        }
        if(reverse_api_address && *reverse_api_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_device_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

