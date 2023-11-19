for(const char i : ss) {
  if(i >= '0' && i <= '9') {
    now *= 10;
    now += (int)(i - '0');
    haveNum = true;
    resProfix += i;
  }

  else {
    if(haveNum) {
      res.Push({val, now, '\0'});
      now = 0;
      haveNum = false;
    }
    if(i != ')') {
      if(i == '(') {
        cnt++;
      } 
      if(cnt <= 0) {
        if(!st.IsEmpty() && getPriority(st.Top().oper) >= getPriority(i)) {
          res.Push(st.Top());
          resProfix += st.Top().oper;
          st.Pop();
        }
      }
      st.Push({op, 0, i});
    }
    
    else {
      cnt--;
      while(st.Top().oper != '(' && !st.IsEmpty()) {
        res.Push(st.Top());
        resProfix += st.Top().oper;
        st.Pop();
      }
      st.Pop();
    }    
  }
} 
