bool cmp(polynomial a, polynomial b) {
  if(a.expon != b.expon) {
    return a.expon > b.expon; // 保證 a.expon > b.expon
  }
  return false; // 如果 a.expon == b.expon，就不交換，否則會 Runtime Error
}
