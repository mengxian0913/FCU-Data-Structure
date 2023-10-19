void MyPoly::ShowPoly() {
  // 遍歷迴圈內所有的項次
  for(int i = 0; i < idx; i++) {
    cout << terms[i].coef << "X^" << terms[i].expon << "+";
    // 輸出係數以及指數
  }
  cout << "\b \n"; // 因為會多輸出一個 + 號，所以使用 "\b" + " " 把它蓋掉。
  return;
}
