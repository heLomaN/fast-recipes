class IObserver {
public:
    virtual on_notify() = 0;
};

class ISubject {
public:
    virtual ~ISubject() {}
    virtual void register(std::shared_ptr<IObserver> o) {
        observers_.push_back(o);
    }
    virtual void unregister()// todo
    virtual void notify() {
        auto itr = observers_.begin();
        while (itr != observers_.end()) {
            auto strong_o = *itr.lock();
            if (strong_o) {
                strong_o->on_notify();
                itr++;
            } else {
                itr = observers_.erase(itr);
            }
        }
    }

private:
    /// use weak_ptr to prevent observer not destroyed
    std::vector<std::weak_ptr<IObserver>> observers_;
};

