#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

struct Settings {
    float c1_bass = 120.53;
    float c1_treble = 52.2;
    float c2_bass = 23.1;
    float c2_treble = 23.1;
    uint gradient = 12; //db/Oct
    uint frequency = 1200; //Hz

    bool filter = false;
    uint hightPass = 1000; //Hz
    uint time = 30;
    uint program = 0;
    uint left = 100;
    uint right = 100;
    uint delay = 0;
    uint precession = 0;
    uint switchs = 0;
};

class SettingsManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float c1_bass READ c1_bass WRITE setC1_bass NOTIFY c1_bassChanged FINAL)
    Q_PROPERTY(float c1_treble READ c1_treble WRITE setC1_treble NOTIFY c1_trebleChanged FINAL)
    Q_PROPERTY(float c2_bass READ c2_bass WRITE setC2_bass NOTIFY c2_bassChanged FINAL)
    Q_PROPERTY(float c2_treble READ c2_treble WRITE setC2_treble NOTIFY c2_trebleChanged FINAL)
    Q_PROPERTY(uint gradient READ gradient WRITE setGradient NOTIFY gradientChanged FINAL)
    Q_PROPERTY(uint frequency READ frequency WRITE setFrequency NOTIFY frequencyChanged FINAL)

    Q_PROPERTY(bool filter READ filter WRITE setFilter NOTIFY filterChanged FINAL)
    Q_PROPERTY(uint hightPass READ hightPass WRITE setHightPass NOTIFY hightPassChanged FINAL)
    Q_PROPERTY(uint time READ time WRITE setTime NOTIFY timeChanged FINAL)
    Q_PROPERTY(uint program READ program WRITE setProgram NOTIFY programChanged FINAL)
    Q_PROPERTY(uint left READ left WRITE setLeft NOTIFY leftChanged FINAL)
    Q_PROPERTY(uint right READ right WRITE setRight NOTIFY rightChanged FINAL)
    Q_PROPERTY(uint delay READ delay WRITE setDelay NOTIFY delayChanged FINAL)
    Q_PROPERTY(uint precession READ precession WRITE setPrecession NOTIFY precessionChanged FINAL)
    Q_PROPERTY(uint switchs READ switchs WRITE setSwitchs NOTIFY switchsChanged FINAL)


public:
    explicit SettingsManager(QObject *parent = nullptr);

    float c1_bass() const;
    void setC1_bass(float newC1_bass);

    float c1_treble() const;
    void setC1_treble(float newC1_treble);

    float c2_bass() const;
    void setC2_bass(float newC2_bass);

    float c2_treble() const;
    void setC2_treble(float newC2_treble);

    uint gradient() const;
    void setGradient(uint newGradient);

    uint frequency() const;
    void setFrequency(uint newFrequency);

    bool filter() const;
    void setFilter(bool newFilter);

    uint hightPass() const;
    void setHightPass(uint newHightPass);

    uint time() const;
    void setTime(uint newTime);

    uint program() const;
    void setProgram(uint newProgram);

    uint left() const;
    void setLeft(uint newLeft);

    uint right() const;
    void setRight(uint newRight);

    uint delay() const;
    void setDelay(uint newDelay);

    uint precession() const;
    void setPrecession(uint newPrecession);

    uint switchs() const;
    void setSwitchs(uint newSwitchs);

private:
    Settings m_settings;

signals:
    void c1_bassChanged();
    void c1_trebleChanged();
    void c2_bassChanged();
    void c2_trebleChanged();
    void gradientChanged();
    void frequencyChanged();
    void filterChanged();
    void hightPassChanged();
    void timeChanged();
    void programChanged();
    void leftChanged();
    void rightChanged();
    void delayChanged();
    void precessionChanged();
    void switchsChanged();
};

#endif // SETTINGS_H
