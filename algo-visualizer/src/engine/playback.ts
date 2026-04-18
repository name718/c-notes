import type { Snapshot } from '../store/useAlgorithmStore';

/**
 * 将算法生成器运行到结束，并收集所有 yield 的快照。
 * @param generator 算法生成器实例
 * @returns 快照数组
 */
export function collectSnapshots(generator: Generator<Snapshot, void, unknown>): Snapshot[] {
  const snapshots: Snapshot[] = [];
  
  let result = generator.next();
  while (!result.done) {
    snapshots.push(result.value);
    result = generator.next();
  }
  
  return snapshots;
}

/**
 * 辅助函数：生成初始状态快照
 */
export function createInitialSnapshot(data: number[], description = 'Initial state'): Snapshot {
  return {
    data: [...data],
    pointers: {},
    activeLines: [],
    description
  };
}
