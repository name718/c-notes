import { Snapshot } from '../../store/useAlgorithmStore';

/**
 * 选择排序算法生成器
 * 1. function selectionSort(arr) {
 * 2.   for (let i = 0; i < arr.length; i++) {
 * 3.     let minIdx = i;
 * 4.     for (let j = i + 1; j < arr.length; j++) {
 * 5.       if (arr[j] < arr[minIdx]) minIdx = j;
 * 6.     }
 * 7.     swap(arr, i, minIdx);
 * 8.   }
 * 9. }
 */
export function* selectionSortGenerator(arr: number[]): Generator<Snapshot, void, unknown> {
  const n = arr.length;
  const currentArr = [...arr];

  yield {
    data: [...currentArr],
    pointers: {},
    activeLines: [1, 2],
    description: 'Starting Selection Sort'
  };

  for (let i = 0; i < n; i++) {
    let minIdx = i;
    yield {
      data: [...currentArr],
      pointers: { i, minIdx },
      activeLines: [3],
      description: `Set initial minIdx to ${i}`
    };

    for (let j = i + 1; j < n; j++) {
      yield {
        data: [...currentArr],
        pointers: { i, minIdx, j },
        activeLines: [4, 5],
        description: `Comparing index ${j} with current min index ${minIdx}`
      };

      if (currentArr[j] < currentArr[minIdx]) {
        minIdx = j;
        yield {
          data: [...currentArr],
          pointers: { i, minIdx, j },
          activeLines: [5],
          description: `Found smaller element, update minIdx to ${j}`
        };
      }
    }

    if (minIdx !== i) {
      [currentArr[i], currentArr[minIdx]] = [currentArr[minIdx], currentArr[i]];
      yield {
        data: [...currentArr],
        pointers: { i, minIdx },
        activeLines: [7],
        description: `Swapping elements at index ${i} and ${minIdx}`
      };
    }
  }

  yield {
    data: [...currentArr],
    pointers: {},
    activeLines: [],
    description: 'Selection Sort completed'
  };
}
