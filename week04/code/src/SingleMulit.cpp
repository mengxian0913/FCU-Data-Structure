void MyPoly::SingleMult(int n) {
  for(int i = 0; i < terms.size(); i++) {
    terms[i].coef *= n;
  }
  return;
}
