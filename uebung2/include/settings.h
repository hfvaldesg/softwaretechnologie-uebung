#ifndef SETTINGS_H
#define SETTINGS_H
#include <memory>

class Settings{
    private:         
        Settings();
    public:
        virtual ~Settings() = default;
        static std::shared_ptr<Settings> getInstace(){
            static std::shared_ptr<Settings> instance;
            if(instance){
                return instance;
            }
            else{
                instace{std::make_shared<Settings>()};
            }
        };
};

#endif