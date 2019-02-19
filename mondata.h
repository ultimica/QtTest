#ifndef _MON_DATA_
#define _MON_DATA_

#include <QDebug>
#include <QObject>

#include <functional>
#include <iostream>
#include <memory>
#include <vector>

class Notifier
{
public:
    virtual void onUpdate()=0;
};

class GenericNotifier : public Notifier
{
public:
    GenericNotifier()=delete;
    GenericNotifier(int notifytype)
    {
          MonitorMan.Register(this,notifytype);
    }
    virtual ~GenericNotifier()
    {
        MonitorMan.UnRegister(this);
    }

    virtual void onUpdate()
    {
          MonitorMan.CallUpdate(target_);
    }
private:
};


// template <class MonitorType>
class ObjMonitor
{
public:
    ObjMonitor() = delete;
    ObjMonitor(const Notifier *dataptr)
    {
        curconnect_ =
            QObject::connect(dataptr, &Notifier::onUpdate, [this]() {  //});
                for (auto funptr : listner) {
                    funptr();
                }
            });
        qDebug() << "Init Connect : " << curconnect_;
    }
    virtual ~ObjMonitor()
    {
        qDebug() << "DisConnect :" << this << "=>"
                 << QObject::disconnect(curconnect_);
    }
    void RegisterListener(std::function<void()> bindfun)
    {
        listner.push_back(bindfun);
    }

private:
    std::vector<std::function<void()>> listner;
    QMetaObject::Connection curconnect_;
};

// template <class T>
// using MON_OBJ = ObjMonitor<T>;
// template <class T>
// using MON_OBJ_SHARE_PTR = std::shared_ptr<MON_OBJ<T>>;


class MyData : public Notifier
{
    Q_OBJECT
public:
    MyData()
    {
       static  GenericNotifier<MyData> g_notifier(this);
    }

    void SetX()
    {
        g_notifier.Notifier();
    }

    int X;
    int Y;

private:
};

class MonitorMan
{
public:
    MonitorMan() {}
    void CreateMyDataObserver(const MyData *objdata)
    {
        data_.reset(new ObjMonitor(objdata));
    }
    void Register(std::function<void()> fun) { data_->RegisterListener(fun); }

private:
    std::shared_ptr<ObjMonitor> data_;
};

#endif
