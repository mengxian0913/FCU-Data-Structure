void MyPoly::Attach(int coef, int expon) {
  for(int i = 0; i < terms.size(); i++) {
     if(terms[i].expon == expon) {
        terms[i].coef += coef;
        return;
    }
  }
  
  terms.pb({coef, expon});
  sort(all(terms), cmp);
  return;
}
