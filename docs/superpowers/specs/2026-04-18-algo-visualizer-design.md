# 算法可视化平台 (AlgoVisualizer) 重构设计规格

## 1. 目标 (Goals)
- **视觉焕新**：采用 IDE 风格的深色模式（The Dark Lab），提供沉浸式极客体验。
- **功能性重构**：实现逻辑与渲染解耦，支持通过 Generator 快速扩展新算法。
- **交互式学习**：支持步进、播放速度控制、变量实时监控及代码高亮同步。

## 2. 核心架构 (Architecture)

### 2.1 状态驱动模型
采用 **Generator-based State Capture**：
1. **Algorithm Logic**: 每种算法实现为一个 `Generator` 函数。
2. **State Snapshot**: 算法在关键步骤 `yield` 一个包含当前数据（数组、指针、状态）的快照。
3. **Playback Engine**: 收集所有快照，控制当前展示哪一帧。
4. **Renderer**: 纯展示组件，仅负责将当前快照渲染成图形。

### 2.2 技术栈
- **框架**: React + TypeScript + Vite
- **动画**: Framer Motion (处理 Layout 变换)
- **状态管理**: Zustand (轻量、高性能)
- **组件库**: Shadcn/UI + Tailwind CSS (提升视觉质感)
- **图标**: Lucide-React

## 3. UI 布局 (The Dark Lab Layout)

### 3.1 侧边栏 (Sidebar - IDE Style)
- **Activity Bar**: 固定在左侧的窄条，包含：算法库、设置、帮助。
- **Nav Pane**: 树状结构，按分类展示算法（排序、树、图、堆等）。

### 3.2 中心区域 (Main Visualizer)
- **Canvas**: 占据主要空间，背景深灰（#0F0F0F）。
- **Floating Controls**: 底部悬浮控制条。
    - 进度条 (Seeker Bar)
    - 播放/暂停
    - 步进 (Step Forward/Backward)
    - 速度调节 (Speed Slider)

### 3.3 右侧面板 (Utility Panel)
- **Code View**: 高亮显示算法代码，支持行高亮同步。
- **State Monitor**: 实时列表显示当前变量（如 `i=5`, `pivot=12`）。
- **Description**: 简短的算法原理说明。

## 4. 扩展性设计 (Extensibility)

### 4.1 算法注册协议
每种新算法只需提供：
- `id`: 唯一标识。
- `logic`: 遵循协议的 Generator 函数。
- `component`: 该算法专用的渲染组件（或使用通用组件）。

### 4.2 数据结构支持
- **Array**: 基础柱状图。
- **Tree**: 节点链接图（SVG/Canvas）。
- **Graph**: 力导向图或固定布局。

## 5. 阶段规划 (Milestones)
1. **基础骨架**: 搭建 IDE 风格布局，集成 Zustand 状态机。
2. **播放引擎**: 实现 Generator 驱动的快照收集与播放逻辑。
3. **首个算法**: 完美复刻选择排序（Selection Sort），验证全链路。
4. **组件库完善**: 完成 UI 细节打磨（圆角、过渡动画、滚动条样式）。
