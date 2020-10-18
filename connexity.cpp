#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


vector<int> connexity_compt(vector<vector<int>> matrix, vector<int> solution) {
  vector<int> connexity(solution.size());
  for (int i=0; i<solution.size(); i++) {
    if (solution[i]==1) connexity[i]++; //On prend en compte le fait qu'un capteur se couvre lui même
    for (int j=0; j<solution.size(); j++) {
      if (matrix[i][j]==1 && solution[j]==1) connexity[i]++;
    }
  }
  return connexity;
}

int main() {

  vector<pair<double,double>> positions;

  //Lecture des positions
  while (cin) {
    int numero;
    double x,y;
    cin >> numero >> x >> y;

    if (numero==0 && x!=0 && y!=0) break;
    else positions.push_back(make_pair(x,y));
  }

  cout << "On a " << positions.size() << " positions possibles." << endl;

  int Rcapt=1; //Pour test, on fixe Rcapt

  //Création de la matrice de couverture (sans prendre en considération où sont les capteurs)
  vector<vector<int>> possible_captors;
  for (int i=0; i<positions.size(); i++) {
    vector<int> captors_i(positions.size());
    for (int j=0; j<positions.size(); j++) {
      double delta = sqrt(pow(positions[i].first - positions[j].first, 2) + pow(positions[i].second - positions[j].second, 2));
      if (delta<=Rcapt) captors_i[j]=1;
    }
    possible_captors.push_back(captors_i);
  }


  //On teste avec une solution ou on met des capteurs partout
  vector<int> solution;
  for (int i=0; i<positions.size(); i++) {
    solution.push_back(1);
  }

  vector<int> con = connexity_compt(possible_captors, solution);

  for (int i=0; i<con.size(); i++) {
    cout << "Le sommet " << i << " est couvert par " << con[i] << " autres sommets." << endl;
  }



}
