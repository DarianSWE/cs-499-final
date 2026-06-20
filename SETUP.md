# CS-499 ePortfolio — GitHub Pages Setup

This folder is your complete, ready-to-publish ePortfolio. Five pages, one
shared stylesheet, and your real code files already linked in.

## What's in here

```
index.html                    ← home page (self-assessment)
code-review.html               ← Milestone One walkthrough + video embed
enhancement-software.html      ← Category One
enhancement-algorithms.html    ← Category Two
enhancement-database.html      ← Category Three
assets/
  css/style.css                ← shared styling, no changes needed
  js/main.js                   ← mobile nav toggle, no changes needed
  files/                       ← your actual code zips + original .cpp
```

## Step 1 — Add your code review video

Open `code-review.html`, find this line near the top of the Video section:

```html
<iframe src="https://www.youtube.com/embed/REPLACE_WITH_VIDEO_ID" ...
```

Replace the URL with your hosted video's **embed link**:

- **YouTube**: upload as Unlisted, click Share → Embed, copy the `src` URL
- **Loom**: open your video, click Share → Embed, copy the `src` URL

If your platform doesn't support embedding, just replace the whole
`<div class="video-frame">...</div>` block with a plain link:
`<a class="btn primary" href="YOUR_VIDEO_URL">Watch Code Review →</a>`

## Step 2 — Push to GitHub

If you already have a GitHub repository set up:

1. Copy every file in this folder into your repo (keep the folder structure exactly as-is)
2. Commit and push:
   ```
   git add .
   git commit -m "Add ePortfolio site"
   git push
   ```

If you're starting fresh:

1. Go to github.com → **New repository** → name it something like `cs499-eportfolio` → Public → Create
2. On the repo page, click **uploading an existing file** and drag in everything from this folder (or use `git clone`, copy the files in, then `git add . && git commit -m "Initial ePortfolio" && git push`)

## Step 3 — Turn on GitHub Pages

1. In your repo, go to **Settings → Pages**
2. Under **Source**, select **Deploy from a branch**
3. Branch: `main`, folder: `/ (root)` → **Save**
4. GitHub gives you a URL like `https://yourusername.github.io/cs499-eportfolio/`
   (takes 1–2 minutes to go live)

## Step 4 — Verify

Visit your new URL and click through all five pages. Confirm:
- The video loads on the Code Review page
- The three download buttons work on each enhancement page
- Navigation works on both desktop and mobile (resize your browser to test the hamburger menu)

That's it — no build step, no dependencies, just static files.

## Optional: custom domain

If you want a custom domain instead of the github.io URL, GitHub's Pages
settings has a "Custom domain" field that walks you through it. Not
required for the assignment, just a nice-to-have if you want it later.
