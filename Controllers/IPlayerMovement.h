#ifndef IPLAYERMOVEMNET_H
#define IPLAYERMOVEMNET_H

class IPlayerMovement {
public:
    virtual ~IPlayerMovement() = default;
    virtual void changePosition() = 0;
};

#endif // IPLAYERMOVEMNET_H
