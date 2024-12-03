#include "settingsmanager.h"


SettingsManager::SettingsManager(QObject *parent)
{

}

float SettingsManager::c1_bass() const
{
    return m_settings.c1_bass;
}

void SettingsManager::setC1_bass(float newC1_bass)
{
    if (qFuzzyCompare(m_settings.c1_bass, newC1_bass))
        return;
    m_settings.c1_bass = newC1_bass;
    emit c1_bassChanged();
}

float SettingsManager::c1_treble() const
{
    return m_settings.c1_treble;
}

void SettingsManager::setC1_treble(float newC1_treble)
{
    if (qFuzzyCompare(m_settings.c1_treble, newC1_treble))
        return;
    m_settings.c1_treble = newC1_treble;
    emit c1_trebleChanged();
}

float SettingsManager::c2_bass() const
{
    return m_settings.c2_bass;
}

void SettingsManager::setC2_bass(float newC2_bass)
{
    if (qFuzzyCompare(m_settings.c2_bass, newC2_bass))
        return;
    m_settings.c2_bass = newC2_bass;
    emit c2_bassChanged();
}

float SettingsManager::c2_treble() const
{
    return m_settings.c2_treble;
}

void SettingsManager::setC2_treble(float newC2_treble)
{
    if (qFuzzyCompare(m_settings.c2_treble, newC2_treble))
        return;
    m_settings.c2_treble = newC2_treble;
    emit c2_trebleChanged();
}

uint SettingsManager::gradient() const
{
    return m_settings.gradient;
}

void SettingsManager::setGradient(uint newGradient)
{
    if (m_settings.gradient == newGradient)
        return;
    m_settings.gradient = newGradient;
    emit gradientChanged();
}

uint SettingsManager::frequency() const
{
    return m_settings.frequency;
}

void SettingsManager::setFrequency(uint newFrequency)
{
    if (m_settings.frequency == newFrequency)
        return;
    m_settings.frequency = newFrequency;
    emit frequencyChanged();
}

bool SettingsManager::filter() const
{
    return m_settings.filter;
}

void SettingsManager::setFilter(bool newFilter)
{
    if (m_settings.filter == newFilter)
        return;
    m_settings.filter = newFilter;
    emit filterChanged();
}

uint SettingsManager::hightPass() const
{
    return m_settings.hightPass;
}

void SettingsManager::setHightPass(uint newHightPass)
{
    if (m_settings.hightPass == newHightPass)
        return;
    m_settings.hightPass = newHightPass;
    emit hightPassChanged();
}

uint SettingsManager::time() const
{
    return m_settings.time;
}

void SettingsManager::setTime(uint newTime)
{
    if (m_settings.time == newTime)
        return;
    m_settings.time = newTime;
    emit timeChanged();
}

uint SettingsManager::program() const
{
    return m_settings.program;
}

void SettingsManager::setProgram(uint newProgram)
{
    if (m_settings.program == newProgram)
        return;
    m_settings.program = newProgram;
    emit programChanged();
}

uint SettingsManager::left() const
{
    return m_settings.left;
}

void SettingsManager::setLeft(uint newLeft)
{
    if (m_settings.left == newLeft)
        return;
    m_settings.left = newLeft;
    emit leftChanged();
}

uint SettingsManager::right() const
{
    return m_settings.right;
}

void SettingsManager::setRight(uint newRight)
{
    if (m_settings.right == newRight)
        return;
    m_settings.right = newRight;
    emit rightChanged();
}

uint SettingsManager::delay() const
{
    return m_settings.delay;
}

void SettingsManager::setDelay(uint newDelay)
{
    if (m_settings.delay == newDelay)
        return;
    m_settings.delay = newDelay;
    emit delayChanged();
}

uint SettingsManager::precession() const
{
    return m_settings.precession;
}

void SettingsManager::setPrecession(uint newPrecession)
{
    if (m_settings.precession == newPrecession)
        return;
    m_settings.precession = newPrecession;
    emit precessionChanged();
}

uint SettingsManager::switchs() const
{
    return m_settings.switchs;
}

void SettingsManager::setSwitchs(uint newSwitchs)
{
    if (m_settings.switchs == newSwitchs)
        return;
    m_settings.switchs = newSwitchs;
    emit switchsChanged();
}
