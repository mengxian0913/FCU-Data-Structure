mystack Postfix;
for(int i = 0; i <= res.top; i++) {
  if(res.a[i].type == op) {
    int a = Postfix.Pop().value;
    int b = Postfix.Pop().value;
    swap(a, b);
    if(res.a[i].oper == '+') {
      a += b;
    } else if(res.a[i].oper == '-'){
      a -= b;
    } else if(res.a[i].oper == '*'){
      a *= b;
    } else {
      a /= b;
    }
    Postfix.Push({val, a, '\0'});
  } else {
    Postfix.Push({val, res.a[i].value, '\0'});
  }
}

