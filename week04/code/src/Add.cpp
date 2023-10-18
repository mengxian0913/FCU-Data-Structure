mypoly mypoly::add(mypoly poly2) {
  MyPoly res;

  int idxR = 0, idxL = 0;
  
  while(idxR < terms.size() && idxL < poly2.terms.size()) {
    if(terms[idxR].expon > poly2.terms[idxL].expon) {
      res.terms.pb(terms[idxR]);
      idxR++;
    }
    else if(terms[idxR].expon < poly2.terms[idxL].expon) {
      res.terms.pb(poly2.terms[idxL]);
      idxL++;
    }
    else {
      res.terms.pb({terms[idxR].coef + poly2.terms[idxL].coef, terms[idxR].expon});
      idxR++;
      idxL++;
    }
  }

  while(idxR < terms.size()) {
    res.terms.pb(terms[idxR]);
    idxR++;
  }

  while(idxL < poly2.terms.size()) {
    res.terms.pb(poly2.terms[idxL]);
    idxL++;
  }

  // cout << "sz: " << sz << "\npoly2.sz: " << poly2.sz << "\nres.sz: " << res.sz << "\n";
  return res;
}

