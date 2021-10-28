class Component{
public:
    virtual ~Component() {}

    virtual void operate() = 0;

};

class Leaf : public Component {
public:
    void operate() override;
};

class Composite : public Component {
public:
    void operate() override {
        for (auto c : children_) {
            c->operate();
        }
    }

    void add_child(Component* c) {
        children_.push_back(c);
    }

    void remove_child(Component* c) {
        children_.erase(c);
    }

    std::vector<Component*> get_children() {
        return children_;
    }

private:
    std::vector<Component*> children_;
};