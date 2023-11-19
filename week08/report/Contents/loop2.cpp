if(haveNum) res.Push({val, now, '\0'});
while (!st.IsEmpty()) {
  res.Push(st.Top()); // 彈出堆疊中剩餘的運算符
  resProfix += st.Top().oper;
  st.Pop();
}
