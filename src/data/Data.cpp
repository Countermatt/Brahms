#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

#include "data/Data.hpp"
#include "sha256/SHA256.hpp"
#include "utils/string.hpp"

using namespace std;


std::string Data::RandomElement(std::vector<std::string> View){

  int rand_val;

  srand(time(NULL));

  if (View.empty()){
    return NULL;
  }

  rand_val = rand() % View.size();

  return View[rand_val];

}

std::string Data::HashIdentifiant(){
  std::string mon_identifiant = mIdentifiant;
  mon_identifiant.append(randString(10));
  auto sha = SHA256();
	sha.update(mon_identifiant);
	uint8_t * digest = sha.digest();
  return SHA256::toString(digest);
}


void Data::PullAdd(std::string element){
  mPullView.push_back(element);
}
void Data::PushAdd(std::string element){
  mPushView.push_back(element);
}
void Data::GlobalAdd(std::string element){
  mGlobalView.push_back(element);
}
void Data::SamplerAdd(std::string element){
  mSamplerView.push_back(element);
}
void Data::StreamAdd(std::string element){
  mStreamView.push_back(element);
}

void Data::SamplerRemove(int i){
  std::vector<std::string> temp;
  temp = SamplerView();
  mSamplerView.clear();
  mSamplerView.shrink_to_fit();

  for(int k = 0; k < (int) temp.size(); k++){
    if(k != i){
      mSamplerView.push_back(temp[k]);
    }
  }
}

void Data::PullReset(){
  mPullView.clear();
  mPullView.shrink_to_fit();
}
void Data::PushReset(){
  mPushView.clear();
  mPushView.shrink_to_fit();
}
void Data::GlobalReset(){
  mGlobalView.clear();
  mGlobalView.shrink_to_fit();
}
void Data::StreamReset(){
  mStreamView.clear();
  mStreamView.shrink_to_fit();
}

void Data::SamplerResize(){
  mSamplerView.shrink_to_fit();
}
