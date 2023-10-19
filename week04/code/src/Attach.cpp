void MyPoly::Attach(int coef, int expon) {
  // 尋找同一個指數，如果有，將係數相加
  for(int i = 0; i < idx; i++) {
     if(terms[i].expon == expon) {
        terms[i].coef += coef;
        return; // 找到就直接結束
    }
  }
  //如果沒有找到，新增在尾巴
  terms[idx++] = {coef, expon};
  sort(terms, terms + idx, cmp); // 自定義排序 bool cmp(polynomial, polynomial);
  return;
}
