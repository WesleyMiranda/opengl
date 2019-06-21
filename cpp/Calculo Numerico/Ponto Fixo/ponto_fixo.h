#ifndef PONTO_FIXO_H
#define PONTO_FIXO_H


class ponto_fixo
{
private:
    int mfixo;
    float mresult;
    void cvtFloat_Fixo();
    float cvtFixo_Float(int i);
    void calcula();

public:
    float mvalor;
    unsigned int mescala;
    ponto_fixo(unsigned int escala, float valor);
    ponto_fixo();

    float show();
    void mprint();


};

#endif // PONTO_FIXO_H
