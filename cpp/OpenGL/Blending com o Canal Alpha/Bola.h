#ifndef BOLA_H
#define BOLA_H

static const float PI=3.14159;

struct Vetor
{
    float x,y;
    Vetor();
    Vetor(float x_, float y_);
};


class Bola
{
    public:
        Bola();
        Bola(float x, float y);
        Bola(float x, float y, float r, float cor[3]);
        ~Bola();
        float get_raio();
        float get_x();
        float get_y();
        void set_x(float x);
        void set_y(float y);
        void set_raio(float r);
        void set_cor(float cor[4]);
        void show();
        Vetor veloc;
        void update();
        float alpha;
        bool continua();
        bool destroi;

    private:
        float m_raio;
        float m_cor[4];
        float m_x;
        float m_y;
        float aleatorio(float a, float b);
};

#endif // BOLA_H
