void MyPoly::SingleMult(int n) {
  for(int i = 0; i < idx; i++) { // 遍歷每一個項次
    terms[i].coef *= n; // 將係數乘上 n
  }
  return;
}
