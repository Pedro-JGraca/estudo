class Paralelepipedo {

    private:
        int x ,y ,z,volume;
    public:
        Paralelepipedo();
        
        void
        setX(int);
        void
        setY(int);
        void
        setZ(int);
        
        int
        getX();
        int
        getY();
        int
        getZ();

        
        void
        computeVolume();
        int
        getVolume();
};