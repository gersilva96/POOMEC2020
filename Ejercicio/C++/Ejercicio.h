class Ejercicio{
    private:
        int radio, height, width;
        float porcentaje;
    public:
        Ejercicio() {
                height = 768;
                width = 1024;
        }
        void setRadio();
        void setPorcentaje();
        int getRadio();
        float getPorcentaje();
};