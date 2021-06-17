// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
//#include "HiddenWordList.h" if using header list makes compile take longer
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    //welcome player
    Super::BeginPlay();
    FBullCowCount Count = {2,3};
    PrintLine(TEXT("Bulls = %i, Cows = %i"), Count.Bulls, Count.Cows);
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordList/TestFile.txt");
    FFileHelper::LoadFileToStringArrayWithPredicate(Isograms, *WordListPath, [](const FString& Word)
        { 
        return Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word); 
        });
    SetupGame();

}
//when the player hits enter
void UBullCowCartridge::OnInput(const FString& Input)
{
    ClearScreen();
    Instructions();
    //check input

    if (bGameOver == true) {
        ClearScreen();
        SetupGame();
    }
    else if (Input == "i" || Input == "I") {
        ClearScreen();
        Instructions();
    }
    else {//check user input
        ProcessGuess(Input);
    }
}
void UBullCowCartridge::ProcessGuess(const FString &Guess) {

    if (HiddenWord == Guess)
    {
        PrintLine(TEXT("%s is the hidden word.\nGood Job!!"),*HiddenWord);
        EndGame();
        return;
    }
    if (Guess.Len() != HiddenWord.Len())//check right number of characters
     {
         PrintLine(TEXT("The hidden word is %i characters long."), HiddenWord.Len());
         return;
     }  //check if isogram
    if (IsIsogram(Guess)==false)
    {   
        PrintLine(TEXT("No Reapeating Letters for isograms"));
        return;
    }
    
     PrintLine(TEXT("%s DOES NOT match hidden word.\nTry Again"),*Guess);

     
    Lives = Lives -1;// remove lives
    PrintLine(TEXT("You have lost a life"));//show lifes left
   
    //check if lives > 0
    if (Lives <= 0)
    {
        EndGame();
    }
    //show the player bull cows
    FBullCowCount Count = GetBullCows(Guess);
    PrintLine(TEXT("You have %i Bulls and %i Cows"),Count.Bulls,Count.Cows); 
    PrintLine(TEXT("Number of Lives Left: %i"), Lives);
}
bool UBullCowCartridge::IsIsogram(const FString &Word)
{   //for each element in the array count the amount of the characters after the element
    //if count is higher than 0 then return false
    int32 count = 0;
    FString LowerWord = Word.ToLower();
    for (size_t j = 0; j < LowerWord.Len(); j++)
    {
        count = 0;
        for (size_t i = j+1; i < LowerWord.Len(); i++)
        {
            if (LowerWord[j] == LowerWord[i]) {
                ++count;
                if (count > 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString> &ArrayGiven) const
{
    TArray<FString> ValidWords;

    for (FString element : ArrayGiven)
    {
        if (element.Len() >= 4 && element.Len() <= 8 &&IsIsogram(element))
        {
                ValidWords.Emplace(element);
        }
    }
    return ValidWords;
}

void UBullCowCartridge::SetupGame()
{
    bGameOver = false;
    HiddenWord = Isograms[FMath::RandRange(0,Isograms.Num()-1)];
    HiddenWord.ToLower();
    Lives = HiddenWord.Len()*2;
    Instructions();
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Game Over"));
    if (Lives<=0)
    {
    PrintLine(TEXT("You ran out of lives."));
    PrintLine(TEXT("The Hidden Word was %s"), *HiddenWord);
    }//Prompt to Play Again, Press enter to play again
    PrintLine(TEXT("Press enter to Play Again."));

}

void UBullCowCartridge::Instructions() const
{ 
    PrintLine(TEXT("Welcome to Bull Cows"));
    PrintLine(TEXT("Please enter the %i character word"), HiddenWord.Len());
    PrintLine(TEXT("Press enter to continue. "));
    PrintLine(TEXT("Number of Lives Left: %i"), Lives);
    PrintLine(TEXT("The HiddenWord is: %s \nAnd %i characters long"), *HiddenWord, HiddenWord.Len());//debug line
}
FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;
    
    //for every index guess is same as index hidden bull count ++
    //if not a bull was it a cow if yes cowcount ++
    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            Count.Bulls++;
            continue;
        }
        for (int32 CowIndex = 0; CowIndex < HiddenWord.Len(); CowIndex++)
        {
            if (Guess[GuessIndex]==HiddenWord[CowIndex])
            {
                Count.Cows++;
                break;
            }
        }
    }
    return Count;
}
