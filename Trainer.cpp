#include "Trainer.h"


Trainer::Trainer()
{

}

Trainer::~Trainer()
{

}

void Trainer::Initailize()
{
    // algoMap 초기화 작업 진행
}


void Trainer::TrainStart()
{

}

void Trainer::Train()
{
	Learn();
}

void Trainer::TrainEnd()
{

}

void Trainer::ChooseAction()
{

}

void Trainer::FetchState()
{

}

void Trainer::CalcReward()
{

}

void Trainer::ResetEnv()
{

}

void Trainer::Learn()
{
    for (int i = 0; i < episodes; ++i) {
        // Reset the environment
        ResetEnv();

        FetchState();

        while (true) {

            ChooseAction();

            FetchState();

            CalcReward();

            Learn();

            NextState();
        }
    }
}

void Trainer::NextState()
{

}







