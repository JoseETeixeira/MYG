namespace BYOND::dmm{

    /**
     * Represents a 3-dimensional position in a DMM file.
     */
    class Location {

    public:
        int x;
        int y;
        int z;

        /**
         * Constructs a new Location with the given coordinates
         *
         * @param x The x-coordinate of this new location
         * @param y The y-coordinate of this new location
         * @param z The z-coordinate of this new location
         */
        Location(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        /**
         * Updates the Location with the given coordinates
         *
         * @param x The x-coordinates
         * @param y The y-coordinates
         * @param z The z-coordinates
         */
        void set(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        /**
         * Takes a step into the given direction.
         *
         * @param dir The direction to step into.
         * @return The new location.
         */
        Location* getStep(int dir) {
            Location *l = new Location(x, y, z);
            if ((dir & 1) != 0)
                l->y++;
            if ((dir & 2) != 0)
                l->y--;
            if ((dir & 4) != 0)
                l->x++;
            if ((dir & 8) != 0)
                l->x--;
            return l;
        }
        

        bool equals(Location* other) {
            if(other == this)
                return true;//TODO: era false
            return x == other->x && y == other->y && z == other->z;
        }
        
        int hashCode() {
            return (x<<16) + (y<<8) + (z);
        }
    };
};