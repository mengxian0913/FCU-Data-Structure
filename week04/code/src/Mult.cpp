MyPoly MyPoly::Mult(MyPoly poly2) {
  MyPoly result, result2; // result 儲存相乘結果， result2 儲存合併後的結果

  // 遍歷每一個組合
  for(int i = 0; i < idx; i++) {
    for(int j = 0; j < poly2.idx; j++) { 
      polynomial current = {terms[i].coef * poly2.terms[j].coef, terms[i].expon + poly2.terms[j].expon}; 
      result.terms[result.idx] = current; // 相乘後，存到 result.terms
      result.idx++;
    }
  }

  sort(result.terms, result.terms + result.idx, cmp); // 排序

  // 合併同一幂次
  polynomial cur = result.terms[0]; 
  for(int i = 1; i < result.idx; i++) {
    if(result.terms[i].expon == cur.expon) {
      cur.coef += result.terms[i].coef;      
    } else {
      result2.terms[result2.idx++] = cur;
      cur = result.terms[i];
    }
  }

  result2.terms[result2.idx++] = cur;

  return result2; // 回傳 result2， terms = result2
}
