/** @type {import('tailwindcss').Config} */
export default {
  content: [
    "./index.html",
    "./src/**/*.{js,ts,jsx,tsx}",
  ],
  theme: {
    extend: {
      colors: {
        background: "#0F0F0F",
        sidebar: "#1A1A1A",
        border: "#2D2D2D",
        accent: "#00E5FF", // 电光青
        "accent-dim": "rgba(0, 229, 255, 0.1)",
      }
    },
  },
  plugins: [],
}
