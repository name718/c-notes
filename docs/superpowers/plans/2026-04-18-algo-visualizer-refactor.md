# 算法可视化平台 (AlgoVisualizer) 重构实现计划

> **面向 AI 代理的工作者：** 必需子技能：使用 superpowers:subagent-driven-development（推荐）或 superpowers:executing-plans 逐任务实现此计划。步骤使用复选框（`- [ ]`）语法来跟踪进度。

**目标：** 将算法可视化网站从基础原型重构为专业的 IDE 风格、逻辑与渲染分离的学习平台。

**架构：** 采用基于 Generator 的状态快照捕获模型。算法逻辑输出快照序列，Playback 引擎控制快照展示，渲染器根据快照绘图。使用 Zustand 进行全局状态管理。

**技术栈：** React, TypeScript, Vite, Framer Motion, Zustand, Tailwind CSS, Lucide-React.

---

### 任务 1：搭建全局状态管理 (Zustand)

**文件：**
- 创建：`algo-visualizer/src/store/useAlgorithmStore.ts`
- 修改：`algo-visualizer/package.json`

- [ ] **步骤 1：安装依赖**
运行：`npm install zustand`

- [ ] **步骤 2：创建 Store**
实现基础的播放控制状态：算法列表、当前快照、当前帧索引、播放状态、速度。

```typescript
import { create } from 'zustand';

interface AlgorithmState {
  steps: any[];
  currentStepIndex: number;
  isPlaying: boolean;
  speed: number;
  setSteps: (steps: any[]) => void;
  nextStep: () => void;
  prevStep: () => void;
  togglePlay: () => void;
  setSpeed: (speed: number) => void;
}

export const useAlgorithmStore = create<AlgorithmState>((set) => ({
  steps: [],
  currentStepIndex: 0,
  isPlaying: false,
  speed: 500,
  setSteps: (steps) => set({ steps, currentStepIndex: 0 }),
  nextStep: () => set((state) => ({ 
    currentStepIndex: Math.min(state.currentStepIndex + 1, state.steps.length - 1) 
  })),
  prevStep: () => set((state) => ({ 
    currentStepIndex: Math.max(state.currentStepIndex - 1, 0) 
  })),
  togglePlay: () => set((state) => ({ isPlaying: !state.isPlaying })),
  setSpeed: (speed) => set({ speed }),
}));
```

- [ ] **步骤 3：Commit**
`git commit -m "feat: add zustand store for algorithm state"`

---

### 任务 2：实现 Generator 播放引擎

**文件：**
- 创建：`algo-visualizer/src/engine/playback.ts`

- [ ] **步骤 1：定义快照接口**
```typescript
export interface Snapshot {
  data: any;
  pointers: Record<string, number>;
  activeLines: number[];
  description: string;
}
```

- [ ] **步骤 2：编写快照收集器**
编写一个函数，接收一个 Generator 并运行它，将所有 `yield` 的值存入数组。

- [ ] **步骤 3：Commit**
`git commit -m "feat: implement playback engine and snapshot types"`

---

### 任务 3：编写首个算法：选择排序 (Selection Sort)

**文件：**
- 创建：`algo-visualizer/src/algorithms/sorting/selectionSort.ts`

- [ ] **步骤 1：实现 Generator 逻辑**
```typescript
export function* selectionSort(arr: number[]) {
  const n = arr.length;
  for (let i = 0; i < n - 1; i++) {
    let minIdx = i;
    yield { data: [...arr], pointers: { i, minIdx }, activeLines: [1], description: 'Initial minIdx' };
    for (let j = i + 1; j < n; j++) {
      yield { data: [...arr], pointers: { i, minIdx, j }, activeLines: [2], description: 'Comparing' };
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
        yield { data: [...arr], pointers: { i, minIdx, j }, activeLines: [3], description: 'New minIdx' };
      }
    }
    [arr[i], arr[minIdx]] = [arr[minIdx], arr[i]];
    yield { data: [...arr], pointers: { i, minIdx }, activeLines: [4], description: 'Swap' };
  }
}
```

- [ ] **步骤 2：Commit**
`git commit -m "feat: implement selection sort generator"`

---

### 任务 4：重构 UI 布局 (IDE 风格)

**文件：**
- 修改：`algo-visualizer/src/App.tsx`
- 修改：`algo-visualizer/src/App.css`

- [ ] **步骤 1：创建三栏布局**
使用 CSS Grid 实现左侧 Sidebar (图标栏 + 目录)、中间 Visualizer、右侧 Info Panel。

- [ ] **步骤 2：应用 The Dark Lab 视觉样式**
设置背景颜色 `#0F0F0F`，边框 `#2D2D2D`，主色调（电光青）。

- [ ] **步骤 3：Commit**
`git commit -m "style: refactor layout to IDE-style dark theme"`

---

### 5. 任务 5：集成渲染器与控制条

**文件：**
- 修改：`algo-visualizer/src/components/Visualizer/ArrayBar.tsx`
- 修改：`algo-visualizer/src/components/Controls/PlaybackControls.tsx`

- [ ] **步骤 1：使用 Framer Motion 实现 Bar 动画**
确保 Bar 在交换位置时有平滑的过渡。

- [ ] **步骤 2：实现进度条与步进功能**
连接 UI 控件到 Zustand Store。

- [ ] **步骤 3：Commit**
`git commit -m "feat: connect UI components to playback store"`

---

### 6. 任务 6：代码高亮与状态监控面板

**文件：**
- 创建：`algo-visualizer/src/components/Panels/CodeExplorer.tsx`
- 创建：`algo-visualizer/src/components/Panels/StateMonitor.tsx`

- [ ] **步骤 1：实现行高亮逻辑**
根据当前快照中的 `activeLines` 数组高亮对应代码行。

- [ ] **步骤 2：显示实时变量**
遍历快照中的 `pointers` 并展示。

- [ ] **步骤 3：Commit**
`git commit -m "feat: add code highlighting and state monitor panels"`
