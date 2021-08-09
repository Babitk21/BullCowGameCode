// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    SetupGame();

    Super::BeginPlay();
    PrintLine(FString::Printf(TEXT("the hidden word is %s"),*hiddenWord));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver==false)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {    
        if(Input==hiddenWord)
        {
           PrintLine(TEXT("you won!"));
           EndGame();
        }
        else
        {
            if(Input.Len() != hiddenWord.Len())
            {
                PrintLine(FString::Printf(TEXT("the hidden word is %i characters,\n you have lost!"),hiddenWord.Len()));
                EndGame();
            }
        }
    }   
}

void UBullCowCartridge::SetupGame()
{
    hiddenWord = TEXT("jean");
    Lives = 3;
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bull-Cows Game"));
    PrintLine(FString::Printf(TEXT("guess the %i letter word"),hiddenWord.Len()));
    PrintLine(TEXT("Press enter to continue...."));
}
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again!"));
}