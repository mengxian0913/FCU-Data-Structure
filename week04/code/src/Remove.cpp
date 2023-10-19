void MyPoly::Remove(int expon) {
  int re_idx = -1; // re_idx 儲存目標項次的 idx ，如果沒有找到就會是 -1
  MyPoly temp; // 儲存新的 terms

  for(int i = 0; i < idx; i++) {
    if(terms[i].expon == expon) {
      re_idx = i; // 更新 re_idx
      break; // 如果找到就可以退出了
    }
  }
  
  if(re_idx == -1) {
    // 如果沒有找到，就提示使用者
    cout << "The expon isn't in the function\n";
    return;
  }


  for(int i = 0; i < idx; i++) { // 遍歷 terms
    if(i == re_idx) { // 如果 idx == re_idx ，代表不需儲存
      continue;
    }

    temp.terms[temp.idx++] = terms[i]; 
  }

  idx = 0; // 初始化 terms
  
  // 將 terms 更新為 temp.terms
  for(int i = 0; i < temp.idx; i++) {
    terms[idx++] = temp.terms[i];
  }

  cout << "Success\n";
  return;
}
