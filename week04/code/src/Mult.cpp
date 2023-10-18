MyPoly MyPoly::Mult(MyPoly poly2) {
  MyPoly result, result2;

  for(int i = 0; i < terms.size(); i++) {
    for(int j = 0; j < poly2.terms.size(); j++) {
      polynomial current = {terms[i].coef * poly2.terms[j].coef, terms[i].expon + poly2.terms[j].expon};
      result.terms.pb(current);
    }
  }

  sort(all(result.terms), cmp);
  
  polynomial cur = result.terms[0];

  for(int i = 1; i < result.terms.size(); i++) {
    if(result.terms[i].expon == cur.expon) {
      cur.coef += result.terms[i].coef;
    } else {
      result2.terms.pb(cur);
      cur = result.terms[i];
    }
  }
  
  return result2;
}

void MyPoly::Remove(int expon) {
  int idx = -1;
  for(int i = 0; i < terms.size(); i++) {
    if(terms[i].expon == expon) {
      idx = i;
      break;
    }
  }
  
  if(idx == -1) {
    cout << "The expon isn't in the function\n";
    return;
  }

  vector<polynomial>::iterator it = terms.begin() + idx;

  terms.erase(it);
  cout << "Success\n";
  return;
}
