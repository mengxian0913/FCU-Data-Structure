void MyPoly::ShowPoly() {
  for(int i = 0; i < terms.size(); i++) {
    cout << terms[i].coef << "X^" << terms[i].expon << "+";
  }
  cout << "\b \n";
  return;
}
