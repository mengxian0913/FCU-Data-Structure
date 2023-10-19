int MyPoly::Lead_Exp() {
  return terms[0].expon; // 因為保證多項式是降序的排列方式，所以取第一個
}
