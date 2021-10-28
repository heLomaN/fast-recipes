/// the target class save its state to memento, client will request for a memento from the target

class Target {
public:
    class Memento {
    public:
        int stata_a;
        std::string state_b;
    };

public:
    void restor_state(Memento state) {
        state_ = state;
    }
    Memento save_state() {
        return state_;
    }

private:
    Memento state_;
}

class Client {
public:
    void do_something() {
        undone_states_.clear();
        ///...do something
        record_state(target_->save_state());
    }

    void undo() {
        auto state = states_.back();
        states_.pop_back();
        undone_states_.push_back(state);

        target_->restor_state(state);
    }

    void redo() {
        auto state = undone_states_.back();
        undone_states_.pop_back();
        states_.push_back(state);

        target_->restor_state(state);
    }

private:
    void record_state(Target::Memento state) {
        states_.push_back(state);
    }
    std::vector<Target::Memento> states_;
    std::vector<Target::Memento> undone_states_;
    Target* target_ = nullptr;
}