#include "Controllers/PlayerController.h"

void PlayerController::changePosition()
{
    if (mKeystates) {
        if (mKeystates[mUpBtnCode]) {
            mUnit.setPositionY(mUnit.getPositionY() - mUnit.getSpeed());
        }
        if (mKeystates[mDownBtnCode]) {
            mUnit.setPositionY(mUnit.getPositionY() + mUnit.getSpeed());
        }
    }
}
