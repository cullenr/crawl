#ifndef GAME_H
#define GAME_H


///*
//  handles-

//  handles contain their component type, index into their memory allocation

//  object ids, simple integrals which are passed to components so the parent can be looked up.

//*/
//// Stuff in here concrete - not part of the 'engine'
//namespace concrete {
//    class ConcreteComponentFactory: public ComponentFactory{
////        void load(Goblin entity);
////        void load(Player player);
//        void load(DroneAi component);
//        void load(NinjaAi component, Entity entity) {
//            handle = NinjaAiCache.addComponent(component); // the component should know its owners serialisation id - possibly different to the 'handle'
//            entity.addHandle(handle); // the handle is the index into the NinjaAiCache and the key to its comonent.
//            // NinjaAiCache.components[entity.getHandle(ConcreteComponents::NinjaAi)]; example lookup. This allows for reduced cache miss.
//        }
//    };

//}

//class PhysicsItem {

//};

//class RenderItem {

//};

//class Entity {
//    Point position;
//    PhysicsItem physicsItem;
//    RenderItem physicsItem;
//};

//class Scene {
//    class Level {
//        void load(std::string path, ComponentFactory* factory);
//        void save(std::string path);
//    };

//    class Menu {

//    };
//};

//class Physics {
//    //this state is not serialised nor replicated between machines.
//    class Model {
//        void addItem(PhysicsItem item);
//        void removeItem(PhysicsItem item);
//    };

//    void update(Model model);
//};

//class Render {
//    class Model {
//        void addItem(RenderItem item);
//        void removeItem(RenderItem item);
//    };
//    void update(Model model);
//};


#include <vector>

class Game
{
public:
    Game();
    ~Game();

    bool load();

    void update(double delta);
    void pause();
    void destroy();
    void serialise();
private:
    //std::vector<System> m_systems;
};

#endif // GAME_H
