#ifndef Options06_h
#define Options06_h

#include "BinModel02.h"

class EurOption
{
   private:
      int N; //steps to expiry
   public:
      void SetN(int N_){N=N_;}
      //Payoff defined to return 0.0 for pedagogical purposes.
      //To use a pure virtual function replace by
      virtual double Payoff(double z)=0;
      //virtual double Payoff(double z){return 0.0;}
      //pricing European option

      //This does not take a strike and does not need to take a strike.
      double PriceByCRR(BinModel Model);
};

class Call: public EurOption
{
   private:
      double K; //strike price

   public:
      void SetK(double K_){K=K_;}
      int GetInputData();
      double Payoff(double z);
};

class Put: public EurOption
{
   private:
      double K; //strike price

   public:
      void SetK(double K_){K=K_;}
      int GetInputData();
      double Payoff(double z);
};

class BullSpread : public EurOption
{
    private:

        double K1;
        double K2;

    public:

        void SetK1(double K1_) {K1 = K1_; };
        void SetK2(double K2_) { K2 = K2_; };

        int GetInputData();
        double Payoff(double z);

};

class BearSpread : public EurOption
{
    private:

        double K1;
        double K2;


public:
        void SetK1(double K1_) { K1 = K1_; };
        void SetK2(double K2_) { K2 = K2_; };

        int GetInputData();
        double Payoff(double z);

};

class DoubleDigital : public EurOption
{
    double K1{};
    double K2{};

public:

    int GetInputData();
    double Payoff(double z);


};

#endif
