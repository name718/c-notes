import { create } from 'zustand';

export interface Snapshot {
  data: number[];
  pointers: Record<string, number>;
  activeLines: number[];
  description: string;
}

interface AlgorithmState {
  // 数据
  steps: Snapshot[];
  currentStepIndex: number;
  
  // 状态
  isPlaying: boolean;
  speed: number;
  
  // 动作
  setSteps: (steps: Snapshot[]) => void;
  nextStep: () => void;
  prevStep: () => void;
  goToStep: (index: number) => void;
  togglePlay: () => void;
  setIsPlaying: (isPlaying: boolean) => void;
  setSpeed: (speed: number) => void;
  reset: () => void;
}

export const useAlgorithmStore = create<AlgorithmState>((set) => ({
  steps: [],
  currentStepIndex: 0,
  isPlaying: false,
  speed: 500,

  setSteps: (steps) => set({ steps, currentStepIndex: 0, isPlaying: false }),
  
  nextStep: () => set((state) => ({ 
    currentStepIndex: Math.min(state.currentStepIndex + 1, state.steps.length - 1) 
  })),
  
  prevStep: () => set((state) => ({ 
    currentStepIndex: Math.max(state.currentStepIndex - 1, 0) 
  })),

  goToStep: (index) => set((state) => ({
    currentStepIndex: Math.max(0, Math.min(index, state.steps.length - 1))
  })),

  togglePlay: () => set((state) => ({ isPlaying: !state.isPlaying })),
  
  setIsPlaying: (isPlaying) => set({ isPlaying }),
  
  setSpeed: (speed) => set({ speed }),

  reset: () => set({ currentStepIndex: 0, isPlaying: false }),
}));
