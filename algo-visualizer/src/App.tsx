import React, { useEffect } from 'react';
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
  Github,
  Layout as LayoutIcon
} from 'lucide-react';
import { motion, AnimatePresence } from 'framer-motion';
import { useAlgorithmStore } from './store/useAlgorithmStore';
import { selectionSortGenerator } from './algorithms/sorting/selectionSort';
import { collectSnapshots } from './engine/playback';

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
  }, []);

  // 自动播放逻辑
  useEffect(() => {
    let interval: number;
    if (isPlaying && currentStepIndex < steps.length - 1) {
      interval = setInterval(() => {
        nextStep();
      }, 1100 - speed);
    }
    return () => clearInterval(interval);
  }, [isPlaying, currentStepIndex, speed, steps.length, nextStep]);

  const currentSnapshot = steps[currentStepIndex] || { data: [], pointers: {}, activeLines: [], description: '' };

  return (
    <div className="flex h-screen w-full bg-background text-white font-sans overflow-hidden">
      {/* 1. Activity Bar (最左侧图标栏) */}
      <aside className="w-12 flex flex-col items-center py-4 bg-background border-r border-border space-y-6">
        <div className="text-accent mb-4">
          <LayoutIcon size={28} />
        </div>
        <div className="flex flex-col space-y-4 text-gray-400">
          <Database size={24} className="hover:text-white cursor-pointer transition-colors" />
          <Settings size={24} className="hover:text-white cursor-pointer transition-colors" />
          <HelpCircle size={24} className="hover:text-white cursor-pointer transition-colors" />
        </div>
        <div className="mt-auto pb-2 text-gray-400">
          <Github size={24} className="hover:text-white cursor-pointer transition-colors" />
        </div>
      </aside>

      {/* 2. Sidebar (算法目录) */}
      <aside className="w-64 bg-sidebar border-r border-border hidden md:flex flex-col">
        <div className="p-4 border-b border-border">
          <h2 className="text-xs font-bold uppercase tracking-widest text-gray-500">Algorithms</h2>
        </div>
        <nav className="flex-1 p-2 space-y-1">
          <div className="px-3 py-2 bg-accent-dim text-accent rounded-md cursor-pointer border-l-2 border-accent text-sm font-medium">
            Selection Sort
          </div>
          <div className="px-3 py-2 hover:bg-white/5 text-gray-400 rounded-md cursor-not-allowed text-sm">
            Quick Sort (Soon)
          </div>
          <div className="px-3 py-2 hover:bg-white/5 text-gray-400 rounded-md cursor-not-allowed text-sm">
            Merge Sort (Soon)
          </div>
        </nav>
      </aside>

      {/* 3. Main Visualizer (中间区域) */}
      <main className="flex-1 flex flex-col relative min-w-0">
        <header className="h-12 border-b border-border flex items-center px-4 bg-background">
          <span className="text-sm text-gray-400">Sorting</span>
          <span className="mx-2 text-gray-600">/</span>
          <span className="text-sm font-medium">Selection Sort</span>
        </header>

        {/* 可视化画布 */}
        <section className="flex-1 relative flex items-end justify-center p-12 overflow-hidden">
          <div className="flex items-end gap-2 h-full max-h-[400px]">
            {currentSnapshot.data.map((num, i) => {
              const isMin = currentSnapshot.pointers.minIdx === i;
              const isI = currentSnapshot.pointers.i === i;
              const isJ = currentSnapshot.pointers.j === i;

              return (
                <motion.div
                  key={i}
                  layout
                  className="flex flex-col items-center gap-2"
                >
                  <motion.div
                    className={`w-12 rounded-t-sm relative transition-colors duration-300 ${
                      isMin ? 'bg-accent' : isI ? 'bg-purple-500' : isJ ? 'bg-orange-500' : 'bg-gray-700'
                    }`}
                    style={{ height: `${(num / 100) * 400}px` }}
                  >
                    <span className="absolute -top-6 left-1/2 -translate-x-1/2 text-xs font-mono">
                      {num}
                    </span>
                  </motion.div>
                  <div className="h-6 flex gap-1">
                    {isI && <span className="text-[10px] bg-purple-500/20 text-purple-400 px-1 rounded border border-purple-500/30">i</span>}
                    {isMin && <span className="text-[10px] bg-accent-dim text-accent px-1 rounded border border-accent/30">min</span>}
                    {isJ && <span className="text-[10px] bg-orange-500/20 text-orange-400 px-1 rounded border border-orange-500/30">j</span>}
                  </div>
                </motion.div>
              );
            })}
          </div>
        </section>

        {/* 底部悬浮控制条 */}
        <div className="absolute bottom-8 left-1/2 -translate-x-1/2 bg-sidebar/80 backdrop-blur-md border border-border px-6 py-3 rounded-full flex items-center gap-6 shadow-2xl">
          <div className="flex items-center gap-2">
            <button onClick={() => goToStep(0)} className="p-2 hover:text-accent transition-colors"><RotateCcw size={18} /></button>
            <button onClick={prevStep} className="p-2 hover:text-accent transition-colors"><ChevronLeft size={18} /></button>
            <button 
              onClick={togglePlay}
              className="w-10 h-10 bg-accent text-black rounded-full flex items-center justify-center hover:scale-105 transition-transform"
            >
              {isPlaying ? <Pause size={20} fill="currentColor" /> : <Play size={20} className="ml-1" fill="currentColor" />}
            </button>
            <button onClick={nextStep} className="p-2 hover:text-accent transition-colors"><ChevronRight size={18} /></button>
          </div>
          
          <div className="h-4 w-px bg-border"></div>
          
          <div className="flex items-center gap-3">
            <span className="text-xs font-mono text-gray-500">Speed</span>
            <input 
              type="range" 
              min="100" 
              max="1000" 
              value={speed} 
              onChange={(e) => setSpeed(Number(e.target.value))}
              className="w-24 accent-accent cursor-pointer"
            />
          </div>

          <div className="h-4 w-px bg-border"></div>

          <div className="flex items-center gap-3">
             <span className="text-xs font-mono text-gray-500">Progress</span>
             <input 
              type="range" 
              min="0" 
              max={steps.length - 1} 
              value={currentStepIndex} 
              onChange={(e) => goToStep(Number(e.target.value))}
              className="w-32 accent-accent cursor-pointer"
            />
          </div>
        </div>
      </main>

      {/* 4. Utility Panel (右侧信息面板) */}
      <aside className="w-80 bg-sidebar border-l border-border hidden lg:flex flex-col">
        <div className="p-4 border-b border-border flex items-center gap-2">
          <Code2 size={18} className="text-accent" />
          <h2 className="text-xs font-bold uppercase tracking-widest text-gray-500">Implementation</h2>
        </div>
        
        <div className="flex-1 overflow-auto p-4 font-mono text-sm">
          <div className="space-y-1">
            {[
              "function selectionSort(arr) {",
              "  for (let i = 0; i < arr.length; i++) {",
              "    let minIdx = i;",
              "    for (let j = i + 1; j < arr.length; j++) {",
              "      if (arr[j] < arr[minIdx]) minIdx = j;",
              "    }",
              "    swap(arr, i, minIdx);",
              "  }",
              "}"
            ].map((line, idx) => (
              <div 
                key={idx}
                className={`px-2 py-0.5 rounded transition-colors ${
                  currentSnapshot.activeLines.includes(idx + 1) 
                    ? 'bg-accent/20 text-accent border-l-2 border-accent -ml-[2px]' 
                    : 'text-gray-500'
                }`}
              >
                <span className="inline-block w-4 mr-4 text-gray-700 text-right select-none">{idx + 1}</span>
                {line}
              </div>
            ))}
          </div>
        </div>

        <div className="p-4 border-t border-border bg-background">
          <h3 className="text-xs font-bold uppercase tracking-widest text-gray-500 mb-3">Status</h3>
          <div className="grid grid-cols-2 gap-2 text-xs font-mono">
            <div className="bg-white/5 p-2 rounded">
              <span className="text-gray-500">i:</span> <span className="text-purple-400">{currentSnapshot.pointers.i ?? '-'}</span>
            </div>
            <div className="bg-white/5 p-2 rounded">
              <span className="text-gray-500">min:</span> <span className="text-accent">{currentSnapshot.pointers.minIdx ?? '-'}</span>
            </div>
            <div className="bg-white/5 p-2 rounded">
              <span className="text-gray-500">j:</span> <span className="text-orange-400">{currentSnapshot.pointers.j ?? '-'}</span>
            </div>
          </div>
          <p className="mt-4 text-xs text-gray-400 italic leading-relaxed">
            {currentSnapshot.description}
          </p>
        </div>
      </aside>
    </div>
  );
}

export default App;
