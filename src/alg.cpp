// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        k = k + 1;
      }
    }
  }
  return k;
}

int countPairs2(int* arr, int len, int value) {
  int left = 0; 
  int k = 0; 
  int right = len - 1;

  while (left < right - 1) {
   int mid = (left + right)/2;
    if (value >= arr[mid])
      left = mid;
    else right = mid;
    }
  
len = right - 1;

  for (int i = len; i>= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == value)
       k = k + 1;
    }
  }
  return k;
}

int countPairs3(int* arr, int len, int value) {
  int left = 0;
  int right = len - 1;
  int k = 0;

  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (value >= arr[mid])
      left = mid;
    else
      right = mid;
  }

  len = right - 1;

  for (int i = 0; i < len; i++) {
    left = i + 1;
    right = len - 1;
    int k2 = 0;
    int v = value - arr[i];

    while (left < right) {
      int mid2 = (left + right) / 2;
      if (arr[mid2] < v)
        left = mid2 + 1;
      else
        right = mid2;
    }

    while (arr[left] == v) {
      k2 = k2 + 1;
      left = left + 1;
    }
    k = k + k2;
  }
  return k;
}
