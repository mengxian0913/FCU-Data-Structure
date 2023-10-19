MyPoly MyPoly::Add(MyPoly poly2) {
  MyPoly res; // res 來儲存相加結果
  int idxR = 0, idxL = 0; // idxR 遍歷 idx, idxL 遍歷 ploy.idx
  while(idxR < idx && idxL < poly2.idx) { // 當 idxR < idx 且 idxL < poly.idx 時執行迴圈
    if(terms[idxR].expon > poly2.terms[idxL].expon) { // 判斷指數大小
      res.terms[res.idx] = terms[idxR];
      idxR++; // 向右移
    }
    else if(terms[idxR].expon < poly2.terms[idxL].expon) {
      res.terms[res.idx] = poly2.terms[idxL];
      idxL++; // 向右移
    }
    else {
      res.terms[res.idx] = {terms[idxR].coef + poly2.terms[idxL].coef, terms[idxR].expon};
      idxR++; // 向右移
      idxL++; // 向右移
    }
    res.idx++; // 每次做完 res.terms 都會多一位，所以 idx++
  }

  while(idxR < idx) {
    res.terms[res.idx] = terms[idxR];
    idxR++;
    res.idx++;
  }

  while(idxL < poly2.idx) {
    res.terms[res.idx] = poly2.terms[idxL];
    idxL++;
    res.idx++;
  }

  return res;
}
