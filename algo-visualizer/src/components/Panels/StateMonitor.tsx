import React from 'react';

interface StateMonitorProps {
  pointers: Record<string, number>;
  description: string;
}

export const StateMonitor: React.FC<StateMonitorProps> = ({ pointers, description }) => {
  return (
    <div className="p-4 border-t border-border bg-background">
      <h3 className="text-[10px] font-bold uppercase tracking-[0.2em] text-gray-500 mb-3">Runtime State</h3>
      <div className="grid grid-cols-2 gap-2 text-xs font-mono">
        {Object.entries(pointers).map(([name, value]) => (
          <div key={name} className="bg-white/5 p-2 rounded flex justify-between items-center border border-white/5">
            <span className="text-gray-500">{name}:</span>
            <span className={name === 'minIdx' ? 'text-accent' : 'text-purple-400'}>{value}</span>
          </div>
        ))}
      </div>
      <div className="mt-4 p-3 bg-accent-dim rounded-md border border-accent/10">
        <p className="text-[11px] text-gray-300 leading-relaxed italic">
          {description}
        </p>
      </div>
    </div>
  );
};
