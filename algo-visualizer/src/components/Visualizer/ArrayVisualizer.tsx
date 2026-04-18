import React from 'react';
import { motion } from 'framer-motion';
import { Snapshot } from '../../store/useAlgorithmStore';

interface ArrayVisualizerProps {
  snapshot: Snapshot;
}

export const ArrayVisualizer: React.FC<ArrayVisualizerProps> = ({ snapshot }) => {
  return (
    <div className="flex items-end gap-2 h-full max-h-[400px]">
      {snapshot.data.map((num, i) => {
        const isMin = snapshot.pointers.minIdx === i;
        const isI = snapshot.pointers.i === i;
        const isJ = snapshot.pointers.j === i;

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
  );
};
