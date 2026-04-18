import { useEffect, useMemo } from 'react';
import { 
  Play, 
  Pause, 
  RotateCcw, 
  ChevronLeft, 
  ChevronRight, 
  Code2, 
  Database,
  Settings,
  HelpCircle,
  Globe,
  Layout as LayoutIcon
} from 'lucide-react';
import { useAlgorithmStore } from './store/useAlgorithmStore';
import { selectionSortGenerator } from './algorithms/sorting/selectionSort';
import { collectSnapshots } from './engine/playback';
import { ArrayVisualizer } from './components/Visualizer/ArrayVisualizer';
import { CodeExplorer } from './components/Panels/CodeExplorer';
import { StateMonitor } from './components/Panels/StateMonitor';

const SELECTION_SORT_CODE = [
  "function selectionSort(arr) {",
  "  for (let i = 0; i < arr.length; i++) {",
  "    let minIdx = i;",
  "    for (let j = i + 1; j < arr.length; j++) {",
  "      if (arr[j] < arr[minIdx]) minIdx = j;",
  "    }",
  "    swap(arr, i, minIdx);",
  "  }",
  "}"
];

function App() {
  const { 
    steps, 
    currentStepIndex, 
    isPlaying, 
    speed,
    setSteps,
    nextStep,
    prevStep,
    togglePlay,
    setSpeed,
    goToStep
  } = useAlgorithmStore();

  // 初始化算法数据
  useEffect(() => {
    const initialData = [45, 23, 89, 12, 67, 34, 90, 56];
    const snapshots = collectSnapshots(selectionSortGenerator(initialData));
    setSteps(snapshots);
  }, [setSteps]);

  // 自动播放逻辑
  useEffect(() => {
    let interval: number;
    if (isPlaying && currentStepIndex < steps.length - 1) {
      interval = window.setInterval(() => {
        nextStep();
      }, 1100 - speed);
    }
    return () => clearInterval(interval);
  }, [isPlaying, currentStepIndex, speed, steps.length, nextStep]);

  const currentSnapshot = useMemo(() => 
    steps[currentStepIndex] || { data: [], pointers: {}, activeLines: [], description: '准备就绪' },
  [steps, currentStepIndex]);

  return (
    <div className="flex h-screen w-full bg-background text-white font-sans overflow-hidden select-none">
      {/* 1. Activity Bar (最左侧图标栏) */}
      <aside className="w-12 flex flex-col items-center py-4 bg-background border-r border-border space-y-6">
        <div className="text-accent mb-4 cursor-pointer hover:scale-110 transition-transform">
          <LayoutIcon size={24} />
        </div>
        <div className="flex flex-col space-y-6 text-gray-500">
          <Database size={20} title="算法库" className="hover:text-accent cursor-pointer transition-colors" />
          <Settings size={20} title="设置" className="hover:text-accent cursor-pointer transition-colors" />
          <HelpCircle size={20} title="帮助" className="hover:text-accent cursor-pointer transition-colors" />
        </div>
        <div className="mt-auto pb-2 text-gray-500">
          <a href="https://github.com" target="_blank" rel="noreferrer" title="GitHub 仓库">
            <Globe size={20} className="hover:text-white cursor-pointer transition-colors" />
          </a>
        </div>
      </aside>

      {/* 2. Sidebar (算法目录) */}
      <aside className="w-60 bg-sidebar border-r border-border hidden md:flex flex-col">
        <div className="p-4 border-b border-border">
          <h2 className="text-[10px] font-bold uppercase tracking-[0.2em] text-gray-500">资源管理器</h2>
        </div>
        <nav className="flex-1 p-2 space-y-1 overflow-y-auto">
          <div className="text-[11px] font-bold text-gray-600 px-3 py-2 uppercase tracking-wider">排序算法</div>
          <div className="px-3 py-2 bg-accent/10 text-accent rounded-md cursor-pointer border-l-2 border-accent text-xs font-medium">
            选择排序 (Selection Sort)
          </div>
          <div className="px-3 py-2 hover:bg-white/5 text-gray-500 rounded-md cursor-not-allowed text-xs transition-colors">
            快速排序 (即将到来)
          </div>
          <div className="px-3 py-2 hover:bg-white/5 text-gray-500 rounded-md cursor-not-allowed text-xs transition-colors">
            归并排序 (即将到来)
          </div>
        </nav>
      </aside>

      {/* 3. Main Visualizer (中间区域) */}
      <main className="flex-1 flex flex-col relative min-w-0 bg-[#0A0A0A]">
        <header className="h-10 border-b border-border flex items-center px-4 bg-background/50 backdrop-blur-sm">
          <span className="text-[10px] text-gray-500 uppercase tracking-wider">排序</span>
          <span className="mx-2 text-gray-700">/</span>
          <span className="text-[10px] text-accent uppercase tracking-wider font-bold">选择排序</span>
        </header>

        {/* 可视化画布 */}
        <section className="flex-1 relative flex items-center justify-center p-12 overflow-hidden">
          <ArrayVisualizer snapshot={currentSnapshot} />
        </section>

        {/* 底部悬浮控制条 */}
        <div className="absolute bottom-10 left-1/2 -translate-x-1/2 bg-[#1A1A1A]/90 backdrop-blur-xl border border-white/10 px-6 py-2 rounded-full flex items-center gap-6 shadow-2xl">
          <div className="flex items-center gap-1">
            <button onClick={() => goToStep(0)} title="重置" className="p-2 text-gray-400 hover:text-accent transition-colors"><RotateCcw size={16} /></button>
            <button onClick={prevStep} title="上一步" className="p-2 text-gray-400 hover:text-accent transition-colors"><ChevronLeft size={20} /></button>
            <button 
              onClick={togglePlay}
              className="w-9 h-9 bg-accent text-black rounded-full flex items-center justify-center hover:scale-105 active:scale-95 transition-all shadow-[0_0_15px_rgba(0,229,255,0.3)]"
            >
              {isPlaying ? <Pause size={18} fill="currentColor" /> : <Play size={18} className="ml-1" fill="currentColor" />}
            </button>
            <button onClick={nextStep} title="下一步" className="p-2 text-gray-400 hover:text-accent transition-colors"><ChevronRight size={20} /></button>
          </div>
          
          <div className="h-4 w-px bg-white/10"></div>
          
          <div className="flex items-center gap-3">
            <span className="text-[10px] font-bold uppercase tracking-wider text-gray-500">速度</span>
            <input 
              type="range" 
              min="100" 
              max="1000" 
              value={speed} 
              onChange={(e) => setSpeed(Number(e.target.value))}
              className="w-20 h-1 bg-white/10 rounded-lg appearance-none cursor-pointer accent-accent"
            />
          </div>

          <div className="h-4 w-px bg-white/10"></div>

          <div className="flex items-center gap-3">
             <span className="text-[10px] font-bold uppercase tracking-wider text-gray-500">进度</span>
             <span className="text-[10px] font-mono text-accent w-8">{currentStepIndex}/{steps.length - 1}</span>
             <input 
              type="range" 
              min="0" 
              max={steps.length - 1} 
              value={currentStepIndex} 
              onChange={(e) => goToStep(Number(e.target.value))}
              className="w-32 h-1 bg-white/10 rounded-lg appearance-none cursor-pointer accent-accent"
            />
          </div>
        </div>
      </main>

      {/* 4. Utility Panel (右侧信息面板) */}
      <aside className="w-72 bg-sidebar border-l border-border hidden xl:flex flex-col">
        <div className="p-4 border-b border-border flex items-center justify-between">
          <div className="flex items-center gap-2">
            <Code2 size={16} className="text-accent" />
            <h2 className="text-[10px] font-bold uppercase tracking-[0.2em] text-gray-500">代码实现</h2>
          </div>
          <span className="text-[10px] text-gray-600 font-mono">selection_sort.ts</span>
        </div>
        
        <CodeExplorer code={SELECTION_SORT_CODE} activeLines={currentSnapshot.activeLines} />

        <StateMonitor pointers={currentSnapshot.pointers} description={currentSnapshot.description} />
      </aside>
    </div>
  );
}

export default App;
