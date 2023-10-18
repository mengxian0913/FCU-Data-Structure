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
