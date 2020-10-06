class Grilla {
    private:
        int ancho, alto;
    public:
        Grilla(int ancho, int alto) {
            this->ancho = ancho;
            this->alto = alto;
        };
        int getAncho() {
            return this->ancho;
        };
        int getAlto() {
            return this->alto;
        };
};