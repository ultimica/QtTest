#ifndef __DELEGATOR__
#define __DELEGATOR__

#include <QObject>

#include <functional>
#include <iostream>
#include <map>
#include <vector>

class NotifyEvent
{
public:
    virtual void onNotifyChanged() = 0;
};

struct NotifyPair
{
    NotifyPair(QObject *rec, std::function<void()> input)
      : receiever_(rec)
      , fun_(input)
    {
    }

    void Exec()
    {
        if (fun_ != nullptr)
            fun_();
    }

    QObject *receiever_;
    std::function<void()> fun_;
};

class QObjectNotifyChanged : public NotifyEvent
{
public:
    void AddListener();
    virtual void onNotifyChanged()
    {
        for (auto singlepair : notifypair_) {
            singlepair->Exec();
        }
    }
    std::vector<NotifyPair *> notifypair_;
};

// template <class T>
// class MonitorData
//{
// public:
//    const T &&data() { return data_; }
//    void setdata(const T &&data) { data_ = data; }

// private:
//    T data_;
//};

// template <class T>
// class Delgator : public QObject
//{
//    Q_OBJECT
// public:
//    void setData(T &input, QList<QString> str)
//    {
//        disconnect(this, 0, 0, 0);

//        data_ = input;
//        emit onNotifyChanged();
//    }
//    T GetData() { return data_; }

//    void Register() {}
// signals:
//    void onNotifyChanged();

// private:
//    T data_;
//};
#endif
