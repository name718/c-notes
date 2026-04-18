import React from 'react';

interface CodeExplorerProps {
  code: string[];
  activeLines: number[];
}

export const CodeExplorer: React.FC<CodeExplorerProps> = ({ code, activeLines }) => {
  return (
    <div className="flex-1 overflow-auto p-4 font-mono text-sm bg-sidebar">
      <div className="space-y-1">
        {code.map((line, idx) => (
          <div 
            key={idx}
            className={`px-2 py-0.5 rounded transition-all duration-200 flex items-center ${
              activeLines.includes(idx + 1) 
                ? 'bg-accent/20 text-accent border-l-2 border-accent -ml-[2px]' 
                : 'text-gray-500'
            }`}
          >
            <span className="inline-block w-6 mr-4 text-gray-700 text-right select-none text-[10px]">{idx + 1}</span>
            <pre className="whitespace-pre-wrap">{line}</pre>
          </div>
        ))}
      </div>
    </div>
  );
};
