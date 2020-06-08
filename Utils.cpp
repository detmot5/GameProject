#include "Utils.h"



namespace Utils {
    int randint(int min, int max) {
        int temp;
        if (max >= min)
            max -= min;
        else
        {
            temp = min - max;
            min = max;
            max = temp;
        }
        return max ? (rand() % max + min) : min;
    }

    UINT16 convertToBlockCoord(float coord) {
        return static_cast<UINT16>(floor(coord / 32.0));
    }

}